# MongoDB Basics

**Definition:** **MongoDB** is an open-source, **document-oriented** NoSQL database. Stores data as **BSON** (Binary JSON) documents. Written in C++. Schema-flexible, horizontally scalable. (imp)

## Terminology (map to RDBMS)
| RDBMS | MongoDB |
|---|---|
| Database | Database |
| Table | **Collection** |
| Row / record | **Document** (JSON/BSON) |
| Column | **Field** |
| Primary key | **_id** (auto if not given) |
| Join | embedding / `$lookup` |

- **Document** — set of key-value pairs, can nest arrays & sub-documents.
- **Collection** — group of documents; no fixed schema.

```json
{
  "_id": 1,
  "name": "raj",
  "dept": "cse",
  "marks": [78, 85, 90]
}
```

## Features
- Flexible / dynamic schema.
- **Indexing** on any field.
- **Replication** — replica set (primary + secondaries) for HA.
- **Sharding** — horizontal partitioning for scale.
- Rich query + **aggregation pipeline**.
- CP system w.r.t. CAP.

## Common shell commands (mongo shell)
```javascript
show dbs
use college                       // switch/create db
db.createCollection("students")

// insert
db.students.insertOne({ name: "raj", dept: "cse", marks: 85 })
db.students.insertMany([
  { name: "asha", dept: "ece", marks: 90 },
  { name: "kiran", dept: "cse", marks: 78 }
])

// read
db.students.find()                         // all
db.students.find({ dept: "cse" })          // filter
db.students.find({ marks: { $gt: 80 } })   // marks > 80
db.students.findOne({ name: "raj" })

// update
db.students.updateOne({ name: "raj" }, { $set: { marks: 88 } })

// delete
db.students.deleteOne({ name: "kiran" })

// count
db.students.countDocuments()
```

## Query operators
- `$gt, $lt, $gte, $lte` — comparison.
- `$in, $nin` — in / not in list.
- `$and, $or` — logical.
- `$set` — update fields.

## Aggregation (group + sum) example
```javascript
db.students.aggregate([
  { $group: { _id: "$dept", avgMarks: { $avg: "$marks" } } }
])
```

- 2 marks: MongoDB = document DB, stores BSON, collection=table, document=row, `_id` = primary key.
