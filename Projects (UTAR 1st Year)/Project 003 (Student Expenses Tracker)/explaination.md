# Student Expense Tracker - current problems

## 1. `viewExpenseHistory()` can crash

You declare `Expense* e;`, but it does not point to a real expense. The next line calls `e->getCategory()`. That uses an unassigned pointer, which can crash the program.

**Fix direction:** do not create a new pointer there. Go through every saved pointer in `exp` and display each one. First check whether `exp` is empty; if it is, say that there are no expenses.

## 2. The menu choices call the wrong feature

The menu says option 3 is `View Report`, but case 3 calls `viewExpenseHistory()`. The menu says option 5 is `View expenses history`, but case 5 prints the goodbye message and exits.

**Fix direction:** decide which option is history and which option exits, then make the printed menu and the `switch` cases agree. Keep reports out of scope until history works.

## 3. Transportation distance will not display

In `addExpense()`, Transportation is checked as `"transportation"`. In `viewExpenseHistory()`, it is checked as `"transport"`. These are different words, so the distance display condition will be false.

**Fix direction:** use the same normalized category text in both places.

## 4. Invalid `Y/N` input still adds another expense

When the user enters something other than `Y` or `N`, the program prints an error but then reaches the end of the loop. The loop starts again and asks for a new expense.

**Fix direction:** keep asking for the continuation answer until it is valid; only then repeat or leave the loop.

## 5. Inputs are not checked yet

Dates and amounts accept any input. A negative amount, impossible date, or letters where a number is expected may make the program behave incorrectly.

**Fix direction:** leave this until after history works, then add simple validation one input type at a time.

## Next feature only

Work on `viewExpenseHistory()` first. Its goal: after adding two expenses, choosing the history menu option shows both saved expenses without crashing.
