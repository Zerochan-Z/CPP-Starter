# Advisor notes

## 2026-07-25 - Student Expense Tracker

**Active file:** `Project 003 (Student Expenses Tracker)/Student Expense Tracker.cpp`.

**Current feature only:** repair `ExpenseTracker::addExpense()`.

**Student needs:** guidance rather than implementation code; explain the repair in small steps.

**Required flow:**
1. Ask for one expense's date and category.
2. Set `distance` to a safe default; ask for it only for Transportation.
3. Ask for subcategory, amount, and description.
4. Create the `Expense` from those values.
5. Store that expense in `exp`.
6. Ask whether to add another expense; repeat only when the user says yes, otherwise exit the function.

**Known issues in current code:** its `while (true)` has no exit decision, it creates an expense but does not store it, non-transport distance can be uninitialized, and category spelling/capitalization conflicts with the displayed choices.

**Latest code state:** the student added `Continue? (Y/N)`, but Transportation currently `break`s before subcategory, amount, description, construction, and storage. The line `exp = new Expense(...)` is also invalid because `exp` is a `vector<Expense*>`; the created pointer must be added as one item to that vector. The distance prompt should be after the common fields (or, at minimum, must not exit the loop).

**2026-07-25 completion check:** the core add-and-store flow is now correct: each iteration resets distance, gathers details, creates `Expense* e`, and calls `exp.push_back(e)`. One small remaining correctness issue: the prompt displays `Transportation` but the condition checks only lowercase `"transportation"`, so a user who follows the prompt will not be asked for distance. Make those match, then test Food and Transportation once each with `N` to leave the loop.

**Next action:** standardize the Transportation text, then manually test one Food expense and one Transportation expense. Only after both runs work should the student select the next feature; the natural next feature is viewing the saved expense history, because it proves the `exp` list actually retained the newly added items.

**Completed:** the student tested both Food and Transportation successfully. `addExpense` is complete for its current scope. Do not change this feature further unless a new bug appears.

**Next feature candidate:** `viewExpenseHistory()` — display each stored `Expense` in `exp`, including date, category, subcategory, amount, description, and distance only when applicable. Start its review as a separate feature.

## Note format preference

Keep earlier entries unchanged. For each later review, append one short new dated section with only the new decision, finding, or next action; do not repeat existing notes.

## 2026-07-26 - History feature review

`viewExpenseHistory()` is the active feature. It currently dereferences an unassigned `Expense* e`, so it can crash. The repair goal is to check for an empty `exp` list, then display every saved expense by iterating through that list. Also correct the menu mapping so the history option actually calls this function. Details are in `Project 003 (Student Expenses Tracker)/explaination.md`.

## 2026-07-26 - History editing guidance

The student changed `viewExpenseHistory()` to declare a local `Expense* exp`, but this hides the class's `vector<Expense*> exp` and is still unassigned. Next edits: remove that local pointer, check `exp.empty()` instead, then loop through the existing vector and call each saved expense's existing `display()` method. Do not redesign the display format during this step.

## 2026-07-27 - History layout decision

Desired format: category is a header; each expense's subcategory and details are rows beneath it. Current loop prints a category header for every expense. Track the last category printed and output a header only when the current expense's normalized category differs. This groups consecutive entries; complete grouping of categories entered in mixed order needs a later grouping/sorting decision.

**Scope guard:** keep advice strictly on `addExpense`; do not move to reports, storage files, budgets, or other menu features.
