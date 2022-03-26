- -2.5: Incorrect implementations
- -2.5: Incorrect output (incorrect probabilities for neighbor encounters)

Score: 95

## Comments:
- You were supposed to have a separate header file for each `struct` (ie. `NewHomeowner.h` for the `newHomeowner struct`, etc.)
- You added `1` to your generated numbers (after the mod), which shifted the range of numbers generated to `1, 2, ..., 100`, which meant that you should have used a less than or equal to check instead of a strict less than.
- Some notes about naming:
	- You don't need the `m_` prefix for member variables (and I would actually recommend against including it), especially since you're using `camelCase`, so the underscore could lead to confusion.
	- Since you're using `camelCase` for variables/functions, you should be using `PascalCase` for types (ie. your `structs`/`classes`).
- Excellent work marking your pass-by-reference parameters as `const` when able.
- Your pre-conditions should never just describe the type of the parameters; the function declaration tells any reader what they need to know about types. Your pre-conditions should be describing additional restrictions that **cannot** be communicated by type (your specification that `aGoodNeighbor` in your `requestAssistance` function must have `m_goodNeighbor == true` is a good example of this). If you do not have any such restrictions, then you should write "none" for the pre-condition.

Very well written and thought out, keep up the good work!