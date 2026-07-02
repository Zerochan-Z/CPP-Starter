/*
Classes created: 
1. Student -> how many student joined club
2. Club -> total clubs + name
3. Number of member -> int total member
4. President & advisor of each club -> string 
5. Club's event -> string event, date, details
*/

/*
Modified version: 
## ✅ Task 3: Club Management System 

---

### 📦 Classes to Create

| Class | Purpose |
|-------|---------|
| **Student** | Represents a UTAR student with personal details |
| **Club** | Represents a club (name, advisor, president, members) |
| **Member** | Represents a student's membership in a club (join date, role) |
| **Event** | Represents a club event (name, date, location, details) |
| **ClubManager** | Manages all clubs, students, and events (optional but useful) |

---

### 🧩 Class Details

#### 1. Student Class

| Attribute | Type | Description |
|-----------|------|-------------|
| `studentID` | int | Unique student ID |
| `name` | string | Student's full name |
| `email` | string | UTAR email |
| `faculty` | string | Faculty (e.g., FCI, FES) |
| `yearOfStudy` | int | 1, 2, 3, or 4 |

| Method | Description |
|--------|-------------|
| `display()` | Show student details |

---

#### 2. Club Class

| Attribute | Type | Description |
|-----------|------|-------------|
| `clubName` | string | Name of the club |
| `clubID` | int | Unique club ID |
| `advisor` | string | Staff advisor name |
| `president` | Student* | Pointer to student who is president |
| `members` | vector<Member*> | List of members |
| `events` | vector<Event*> | List of events |

| Method | Description |
|--------|-------------|
| `addMember(Student* s)` | Add a student as member |
| `removeMember(Student* s)` | Remove a member |
| `addEvent(Event* e)` | Add an event |
| `display()` | Show club details |

---

#### 3. Member Class

| Attribute | Type | Description |
|-----------|------|-------------|
| `student` | Student* | Pointer to the student |
| `club` | Club* | Pointer to the club |
| `joinDate` | string | Date joined (e.g., "01-07-2026") |
| `role` | string | "Member", "Vice President", "President" |
| `isActive` | bool | True if still a member |

| Method | Description |
|--------|-------------|
| `display()` | Show membership details |

---

#### 4. Event Class

| Attribute | Type | Description |
|-----------|------|-------------|
| `eventName` | string | Name of event |
| `eventDate` | string | Date of event |
| `time` | string | Start time |
| `location` | string | Venue (e.g., "DK1") |
| `club` | Club* | Pointer to organizing club |
| `attendees` | vector<Student*> | List of attendees |

| Method | Description |
|--------|-------------|
| `addAttendee(Student* s)` | Add student to attendees |
| `display()` | Show event details |

---

#### 5. ClubManager Class (Optional)

| Attribute | Type | Description |
|-----------|------|-------------|
| `clubs` | vector<Club*> | All clubs |
| `students` | vector<Student*> | All students |
| `events` | vector<Event*> | All events |

| Method | Description |
|--------|-------------|
| `addClub(Club* c)` | Add a club |
| `addStudent(Student* s)` | Register a student |
| `findClub(string name)` | Search for a club |
| `displayAllClubs()` | Show all clubs |
| `displayAllStudents()` | Show all students |

---

### 🔗 How They Interact

```
┌──────────────────────────────────────────────────────────┐
│                    ClubManager                           │
│  manages all:                                           │
│  ┌────────┐  ┌────────┐  ┌────────┐  ┌────────┐       │
│  │ Clubs  │  │Students│  │ Events │  │Members │       │
│  └────────┘  └────────┘  └────────┘  └────────┘       │
│       │           │           │           │             │
└───────┼───────────┼───────────┼───────────┼────────────┘
        │           │           │           │
        ▼           ▼           ▼           ▼
┌────────────┐ ┌────────────┐ ┌────────────┐ ┌────────────┐
│    Club    │ │   Student  │ │   Event    │ │   Member   │
│ - name     │ │ - name     │ │ - name     │ │ - role     │
│ - advisor  │ │ - id       │ │ - date     │ │ - joinDate │
│ - president│ │ - email    │ │ - location │ │ - isActive │
│ - members  │ │ - faculty  │ │ - attendees│ │            │
│ - events   │ │            │ │            │ │            │
└────────────┘ └────────────┘ └────────────┘ └────────────┘
      │            │            │            │
      └────────────┴────────────┴────────────┘
                     all connected via pointers
```

---

### 📝 Example Relationships

| Relationship | How it works |
|--------------|--------------|
| **Club has many Members** | `Club` has `vector<Member*>` |
| **Member belongs to one Club** | `Member` has `Club*` |
| **Club has one President** | `Club` has `Student* president` |
| **Club has many Events** | `Club` has `vector<Event*>` |
| **Event has many Attendees** | `Event` has `vector<Student*>` |
| **Student can join many Clubs** | `Student` can be in multiple `Member` objects |

---

### ✅ Your Original Design vs Improved Design

| Your Idea | Improved |
|-----------|----------|
| `Student` class | ✅ Good – keep it |
| `Club` class | ✅ Good – keep it |
| `Number of member` (int) | Changed to `vector<Member*>` (better) |
| `President & advisor` (string) | Changed to `Student* president` and `string advisor` |
| `Club's event` (string) | Changed to `Event` class (better) |

*/