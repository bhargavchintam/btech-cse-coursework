# HDFS Read and Write Operations

Client always talks to the **NameNode for metadata** and to the **DataNodes for actual data**. Bulk data never passes through the NameNode.

## Write operation (client → NameNode → DataNode pipeline)

Steps (imp):
1. Client calls `create()` on the file.
2. Client asks **NameNode** to create the file entry in the namespace. NameNode checks permissions and that file does not already exist.
3. Client splits data into packets and asks NameNode for a list of DataNodes for the first block (list size = replication factor).
4. NameNode returns e.g. **DN1 → DN2 → DN3** (chosen by rack awareness).
5. Client writes the block to **DN1 only**. DN1 forwards to DN2, DN2 forwards to DN3 — this is the **write pipeline**.
6. Each DataNode sends an **acknowledgement** back up the pipeline (DN3 → DN2 → DN1 → client).
7. When all packets of the block are acked, client requests DataNodes for the next block and repeats.
8. Client calls `close()`. NameNode commits the file once minimum replicas are written.

```
Client ---block---> DN1 ---> DN2 ---> DN3
       <---ack---- DN1 <--- DN2 <--- DN3
```

## Read operation (client → NameNode → DataNode)

Steps:
1. Client calls `open()` on the file.
2. Client asks **NameNode** for the block locations of the file.
3. NameNode returns, for each block, the list of DataNodes holding it, **sorted by nearness** to the client (data locality).
4. Client reads each block from the **closest DataNode** directly.
5. If a DataNode fails during read, client retries the **next nearest** replica of that block and remembers the bad node.
6. Client reads block after block in order, then calls `close()`.

```
Client --(1) block locations--> NameNode
Client --(2) read block1------> nearest DataNode
Client --(3) read block2------> nearest DataNode
```

## Key points (differentiate read vs write)
| | Write | Read |
|--|-------|------|
| NameNode role | allot block IDs + DataNode list | return block locations |
| DataNode flow | pipeline DN1→DN2→DN3 | client reads nearest replica |
| Failure handling | drop bad DN, continue pipeline with remaining | switch to next replica |
| Replication | writes all replicas | reads any one replica |
