# Unit 1 — Introduction to Database Systems

A database is a collection of related data, and a DBMS is the software that lets you
define, store, retrieve and manage that data. Before the DBMS approach, applications
kept their data in ordinary operating-system files, each program owning its own files
and its own code to read them. That is the "file-processing system", and the whole
point of Unit 1 is why we moved away from it.

## File-system approach vs DBMS

Say the college keeps student data. The accounts office has a FEES file, the exam
section has a MARKS file, the library has a MEMBERS file. Each was written separately,
often in COBOL/C, each with its own record format. This works until the data starts
overlapping — and it always does.

| Drawback of files | What happens | How a DBMS fixes it |
|---|---|---|
| Data redundancy | A student's name/address stored in fees, exam and library files | One table, referenced by key — stored once |
| Inconsistency | Address changed in fees file but not in library file → two versions | Update once; controlled redundancy only |
| Data isolation | Data scattered across files in different formats, hard to combine | Uniform schema, one query language (SQL) |
| Program–data dependence | Change a file's layout → every program reading it must be recompiled | Data independence (see below) |
| No concurrency control | Two clerks update the same record at once → one update lost | Locking, isolation levels |
| No atomicity | Transfer debits A, crashes before crediting B → money vanishes | Transactions: all-or-nothing |
| Integrity hard to enforce | "balance ≥ 0" scattered in application code, easy to forget | Constraints declared once in the schema |
| Poor security | File-level access only, can't hide one column from a user | Views and GRANT/REVOKE at fine grain |

> Sir hammered this: redundancy is not just wasted space, it *causes* inconsistency.
> That link is a favourite one-mark question.

The DBMS puts the data in one place, describes it once, and hands out a single language
to get at it. The application no longer knows or cares how the bytes sit on disk.

## Three-schema architecture (ANSI-SPARC)

The ANSI/SPARC study group defined three levels of abstraction. The idea is to separate
what a user sees from how the data is actually stored, so one can change without
disturbing the other.

```
        +----------------------------------------------+
        |   EXTERNAL LEVEL  (user views)               |
        |   view A: clerk     view B: student portal   |
        +----------------------------------------------+
                        |   external / conceptual mapping
        +----------------------------------------------+
        |   CONCEPTUAL LEVEL  (logical schema)         |
        |   all tables, columns, relationships,        |
        |   constraints — the whole DB, one description|
        +----------------------------------------------+
                        |   conceptual / internal mapping
        +----------------------------------------------+
        |   INTERNAL LEVEL  (physical storage)         |
        |   files, blocks, indexes, B+ trees on disk   |
        +----------------------------------------------+
```

- **External level** — what each user or application sees. A view. The exam clerk sees
  marks but not fees; the student sees only their own row. Many external schemas per DB.
- **Conceptual level** — the community view: every entity, attribute and relationship,
  and the integrity constraints. One conceptual schema. This is what the DBA designs.
- **Internal level** — how it is physically stored: record layout, which indexes exist,
  compression, placement on disk. One internal schema.

The two mappings between the levels are what buy us *data independence*.

### Logical vs physical data independence

- **Physical data independence** — change the internal schema (add an index, change the
  file organisation, move to a faster disk) without touching the conceptual schema.
  Only the conceptual/internal mapping is adjusted. This one is easy and DBMSs give it
  routinely.
- **Logical data independence** — change the conceptual schema (add a new column, split
  a table) without disturbing existing external views or the programs that use them.
  Harder to achieve, because views are built directly on the logical schema.

> Trick to remember: logical independence protects the *user views* above it;
> physical independence protects the *logical schema* above it. Each level shields
> the one directly on top.

## Data models

A data model is a set of concepts for describing data, relationships, semantics and
constraints. The main ones, in the order they appeared:

- **Hierarchical** — data as a tree, parent–child links (IBM IMS). One parent per
  child; a many-to-many relationship is awkward. Navigate by following pointers.
- **Network** — a graph; a record can have several parents (CODASYL DBTG). More flexible
  than hierarchical but the programmer still navigates pointer sets by hand.
- **Relational** — data as tables (relations) of rows and columns; Codd, 1970. No
  pointers exposed; you say *what* you want with a query, not *how* to fetch it.
- **Object-oriented / object-relational** — stores objects with methods, handles complex
  types (images, CAD, nested data) that flat tables model clumsily.
- **ER model** — an entity–relationship diagram. Not an implementation model; it is a
  *conceptual* design tool used to plan a database before mapping it to relational tables.

**Why relational won:** simple tabular structure anyone can picture; a firm mathematical
base (relational algebra and calculus) so queries can be optimised; physical and logical
data independence built in; and a declarative, standard language (SQL). The programmer
stops chasing pointers and just describes the result.

## Schema vs instance

- **Schema** — the *design* / structure of the database: the tables, columns, types and
  constraints. Set at design time, changes rarely. Like the `CREATE TABLE` statements.
- **Instance** (state) — the actual data in the database at a given moment. Changes with
  every insert, update, delete.

> One schema, many instances over time. Compare to programming: schema is the type
> declaration, instance is the value of the variable right now.

## Database users and the DBA

- **DBA (Database Administrator)** — owns the database. Responsibilities: designing the
  conceptual and internal schemas; granting and revoking access (security, `GRANT`/
  `REVOKE`); backup and recovery; tuning performance (indexes, storage); enforcing
  integrity rules; deciding storage structures.
- **Database designers** — identify the data and design the schema (often the DBA early on).
- **Application programmers** — write the programs and screens that call the database.
- **Sophisticated / naive end users** — analysts who write their own ad-hoc SQL, versus
  clerks who only use canned forms (an ATM user is a naive end user).

## Advantages of a DBMS

- Controlled redundancy — data stored once, redundancy only where deliberate.
- Consistency and enforced integrity constraints.
- Sharing of data by many users, with concurrency control.
- Restricted, fine-grained access (security via views and privileges).
- Backup and recovery from failures.
- Data independence — insulates programs from storage changes.
- Uniform data administration and a standard query language.

## Solved short-answer items

**Q1. Distinguish physical and logical data independence with one example each.**
**Ans:** Physical data independence is the ability to change the internal (storage)
schema without changing the conceptual schema — e.g. creating an index on `emp(sal)`
to speed queries: no table definition or program changes. Logical data independence is
the ability to change the conceptual schema without changing external views/programs —
e.g. adding a `mobile` column to `emp`: existing views that never referenced it, and the
programs on them, keep working unchanged. Logical independence is harder because views
sit directly on the logical schema.

**Q2. Give two problems of the file-processing approach that a DBMS solves, and how.**
**Ans:** (1) *Data redundancy and inconsistency* — the same fact (a student's address)
is copied across the fees and library files, so an update to one leaves the other stale.
A DBMS stores it once and references it by key, so there is a single value to update.
(2) *Atomicity / concurrency failures* — a fund transfer that debits one account and
crashes before crediting the other loses money, and two clerks editing one record can
overwrite each other. A DBMS wraps such work in a transaction (all-or-nothing) and uses
locking so concurrent updates do not corrupt the data.
