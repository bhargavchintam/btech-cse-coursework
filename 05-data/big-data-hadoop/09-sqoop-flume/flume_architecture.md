# Flume Architecture

Flume runs as one or more **agents**. Each agent is a JVM process with three parts: **Source -> Channel -> Sink**.

## Agent
- **Definition:** an independent Flume process (JVM) that hosts sources, channels and sinks.
- Configured through a properties file. One config can define several agents; you start one by name.
- Events flow through the agent from source to sink.

## Source
- Receives / reads events from an external source and puts them into the channel.
- Examples:
  - **spooldir** — reads new files dropped into a directory.
  - **exec** — runs a command like `tail -F /var/log/app.log`.
  - **netcat**, **syslog**, **avro**, **http**, **Kafka source**.
- A source can write to one or more channels.

## Channel
- **Definition:** a buffer / queue between source and sink. Holds events until the sink consumes them.
- Gives reliability — decouples fast source from slow sink.
- Types:
  - **memory channel** — fast, but events lost if agent crashes (in RAM).
  - **file channel** — durable, events written to disk (survives restart).
  - **Kafka channel**.

## Sink
- Takes events from the channel and delivers them to the destination (or next agent).
- Examples:
  - **HDFS sink** — writes events to HDFS.
  - **HBase sink**, **logger sink** (debug), **avro sink** (to next agent), **Kafka sink**.
- Removes the event from the channel only after it is successfully delivered (transaction).

## Flow (imp)
```
External source -> [ Source -> Channel -> Sink ] -> HDFS
                        \______ Agent ______/
```

## Reliability
- Two transactions per hop: source->channel (put) and channel->sink (take).
- Event removed from channel only after the sink confirms delivery -> **no data loss**.
- If sink fails, event stays in channel and is retried.

## Multi-agent / topologies
- **Multi-hop** — sink of agent1 (avro) -> source of agent2 (avro). Chain agents.
- **Fan-in** — many agents feed one collector agent -> HDFS.
- **Fan-out** — one source writes to multiple channels/sinks (replicating or multiplexing).

(asked prev year) Draw the agent: label Source, Channel, Sink and show event flow to HDFS.
