# Unit 2 — Entity-Relationship Model

The ER model is a high-level conceptual data model. Before you write any CREATE
TABLE, draw the mini-world (entities, attributes, how they relate), then map that
drawing to relations. Proposed by Peter Chen, 1976.

## Entity and entity set

- **Entity** — a thing in the real world with independent existence. Can be
  physical (a student, a car) or conceptual (a course, a loan account).
- **Entity set** — a collection of entities of the same type, sharing the same
  attributes. STUDENT is an entity set; the student named 'Ravi' is one entity.
- Notation: entity type drawn as a **rectangle** — `[ STUDENT ]`.

## Attributes

Each entity is described by attributes; each attribute's value is drawn from a
*domain* (its allowed set of values).

- **Simple (atomic)** — cannot be divided. `age`, `gender`. Drawn as an oval.
- **Composite** — divisible into sub-parts. `name` -> {fname, mname, lname};
  `address` -> {street, city, pin}. Sub-attributes hang off the parent oval.
- **Single-valued** vs **multivalued** — `dob` has one value; `phone` a set of
  values (drawn as a **double oval**).
- **Derived** — computed from another attribute, not stored. `age` from `dob`.
  Drawn as a **dashed oval**.
- **Key attribute** — uniquely identifies each entity. `usn` for a student;
  drawn by **underlining** the name. (A NULL value = not known / not applicable.)

```
   ______     (fname) (lname)
  ( usn )        \    /                 usn underlined  = key
   ------        [name]                 ((phone))       = multivalued
      \           |     ((phone))       /(age)/         = derived
       +----------+---------+---/(age)/
       |       STUDENT      |
       +--------------------+
```

> Sir kept saying: underline = key, double oval = multivalued, dashed = derived.
> Most of the objective questions on ER notation are exactly this.

## Relationship and relationship set

- **Relationship** — an association among two or more entities. 'Ravi ENROLLS
  in DBMS'.
- **Relationship set** — a set of relationships of the same type. Drawn as a
  **diamond** joining the participating entity rectangles.
- **Degree** — number of entity sets participating in the relationship:
  - **Unary (1)** — recursive, entity related to itself. EMPLOYEE *manages* EMPLOYEE.
  - **Binary (2)** — the common one. STUDENT *enrolls* COURSE.
  - **Ternary (3)** — three entities. SUPPLIER *supplies* PART *to* PROJECT.
- **Role** — the function an entity plays. In the recursive *manages*, one
  employee is 'manager', the other is 'subordinate'.
- **Descriptive attribute** — an attribute on the relationship itself. `grade`
  belongs on ENROLLS — it makes sense only for a (student, course) pair.

## Mapping cardinalities

Cardinality ratio = how many entities of one set can associate with entities of
the other. For a binary relationship:

**One-to-one (1:1)** — one A relates to at most one B and vice versa.
```
  [EMPLOYEE] --1--<MANAGES>--1-- [DEPARTMENT]      one manager heads one dept
```

**One-to-many (1:N)** — one A relates to many B, but each B to one A.
```
  [DEPARTMENT] --1--<HAS>--N-- [EMPLOYEE]   -- dept has many emps, each emp one dept
```

**Many-to-many (M:N)** — one A relates to many B and one B to many A.
```
  [STUDENT] --M--<ENROLLS>--N-- [COURSE]    -- a student many courses, vice versa
```

Chen puts the 1/N/M on the lines. The (min,max) style writes `(1,1)`, `(0,N)` on
each edge — the pair = (minimum, maximum) participation of that entity.

## Participation constraints

Whether *every* entity must take part in the relationship:

- **Total participation** — every entity in the set must participate. Drawn with a
  **double line** from entity to relationship.
- **Partial participation** — some may not participate. Single line.

```
  [EMPLOYEE] ====<WORKS_FOR>---- [DEPARTMENT]
      total (double line)          partial (single line)
```

Reading: every employee must work for some department (total, double line), but a
department may exist with no employee (partial). Total = *existence dependency*.

## Weak entity sets

A **weak entity** has no key attribute of its own — it can't be identified by
its own attributes alone. It depends on another (the **owner / identifying**
entity).

- Weak entity: **double rectangle**; identifying relationship: **double diamond**.
- **Partial key (discriminator)** — the attribute distinguishing weak entities of
  the *same* owner. Drawn with a **dashed underline**.
- Full key of the weak entity = owner's primary key + partial key.
- A weak entity always has **total participation** in its identifying
  relationship (it can't exist without the owner).

```
  [EMPLOYEE] ====<< HAS >>==== [[ DEPENDENT ]]
                                  ....name.... (dashed underline = partial key)
```
A DEPENDENT is keyed by (owner's empno + name): 'Anita' alone isn't unique across
the company, 'empno 7566 + Anita' is.

## A full worked example — a college

Entities: STUDENT, COURSE, INSTRUCTOR. Relationships: ENROLLS (student–course),
TEACHES (instructor–course).

```
   ______                                     _______
  ( usn )                                    ( empid )
   ------                                     -------
      |                                          |
  +---------+     M   +---------+   N     +------------+
  | STUDENT |=========< ENROLLS >=========|   COURSE   |
  +---------+         +---------+         +------------+
      |                   |                    |   N
   (name)             (grade)              (cid)|
   (sem)                                        |
                                          +-----------+   1   +--------------+
                                          |  TEACHES  |>------|  INSTRUCTOR  |
                                          +-----------+       +--------------+
                                                                (empid) (name)
```

Constraints read off the diagram:
- ENROLLS is **M:N**, with `grade` as its descriptive attribute. STUDENT has
  **total** participation (double line) — every student must enroll in a course.
- TEACHES is **1:N** from INSTRUCTOR to COURSE — one instructor teaches many
  courses, each course has one instructor.
- `usn`, `cid`, `empid` are the key attributes (underlined).

## EER features

Extended ER (EER) adds abstraction for complex schemas.

- **Generalization** — bottom-up. Combine similar entity sets into a higher
  supertype. CAR and TRUCK -> VEHICLE.
- **Specialization** — top-down. Split a supertype into subtypes by some
  distinguishing property. EMPLOYEE -> {ENGINEER, MANAGER, SALESMAN}.
- Drawn with a **triangle** labelled *ISA* between the supertype and subtypes.
  Subtypes **inherit** all attributes of the supertype plus add their own.
- Constraints on specialization:
  - **Disjoint (d)** vs **overlapping (o)** — can an entity belong to more than
    one subtype at once?
  - **Total** (double line) vs **partial** — must every supertype entity belong
    to some subtype?

```
          [ EMPLOYEE ]
               |
              /_\  ISA   (d = disjoint)
             /   \
      [ ENGINEER ] [ MANAGER ]
```

- **Aggregation** — treats a whole relationship (with its entities) as one
  higher-level entity, so it can itself join another relationship. E.g. box
  (EMPLOYEE WORKS_ON PROJECT) so MANAGER can *monitor* that whole assignment.

## Mapping an ER diagram to relational tables

The 7-step ER-to-relational algorithm (Elmasri & Navathe):

1. **Strong entity** -> a table with all its simple attributes; the entity's key
   becomes the primary key.
   `STUDENT(usn PK, name, sem)`
2. **Weak entity** -> a table with its attributes + the owner's PK as a foreign
   key; PK = owner PK + partial key.
   `DEPENDENT(empno FK, dname, ...); PK(empno, dname)`
3. **1:1 relationship** -> put the PK of one side into the other as a FK (choose
   the side with total participation to hold it).
   `DEPARTMENT(deptno PK, ..., mgr_empno FK)`
4. **1:N relationship** -> put the PK of the '1' side into the 'N'-side table as
   a FK. No new table.
   `EMPLOYEE(empno PK, ..., deptno FK)` for DEPARTMENT 1—N EMPLOYEE.
5. **M:N relationship** -> a **new table** whose PK is the combination of both
   entities' PKs; add any descriptive attributes.
   `ENROLLS(usn FK, cid FK, grade); PK(usn, cid)`
6. **Multivalued attribute** -> a **new table** holding the attribute + the
   owning entity's PK; PK = both together.
   `STUDENT_PHONE(usn FK, phone); PK(usn, phone)`
7. **N-ary relationship** -> a new table with the PKs of all participating
   entities as a composite key, plus descriptive attributes.

Composite attributes flatten to simple columns; derived ones aren't stored.

## Solved problems

**1. Draw an ER diagram for a BANK: a bank has branches; each branch holds many
accounts; a customer can hold many accounts.**

```
   (bname)                (acc_no)              (cid)
      |                      |                    |
  +--------+  1   +----+  N +---------+  M  +----+ N +----------+
  | BRANCH |======<HAS>=====| ACCOUNT |=====<HOLDS>==| CUSTOMER |
  +--------+      +----+    +---------+     +-----+   +----------+
                                (balance)
```
**Ans:** BRANCH–ACCOUNT is 1:N (each account in one branch, total on ACCOUNT).
ACCOUNT–CUSTOMER is M:N (an account can be jointly held). Keys: `bname`, `acc_no`,
`cid`.

**2. Map this ER to relational tables:** DEPARTMENT(deptno, dname) 1—N
EMPLOYEE(empno, ename, sal), and EMPLOYEE M—N PROJECT(pno, pname) with descriptive
attribute `hours`.

**Ans:**
```
DEPARTMENT(deptno PK, dname)
EMPLOYEE(empno PK, ename, sal, deptno FK -> DEPARTMENT)      -- rule 4, 1:N
PROJECT(pno PK, pname)
WORKS_ON(empno FK, pno FK, hours); PK(empno, pno)            -- rule 5, M:N
```
The 1:N needs no separate table (deptno moves into EMPLOYEE); the M:N does.

**3. Identify the weak entity:** A HOTEL has many ROOMs numbered 101, 102 … but
room 101 exists in every hotel, so `room_no` is not globally unique.

**Ans:** ROOM is the **weak entity** — `room_no` identifies a room only *within a
hotel*. HOTEL is the owner (`hotel_id`); the identifying relationship is HOTEL
*HAS* ROOM (double diamond). Partial key = `room_no`; full key of ROOM =
(`hotel_id`, `room_no`). ROOM has total participation — no room without a hotel.

> Exam trap I lost marks on in IA1: the weak entity's key is *owner key + partial
> key*, not the partial key alone. Always write both.
