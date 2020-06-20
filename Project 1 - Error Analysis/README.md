# Project 1 - Error Analysis

Testing varying types of input
- all three inputs being 0 results in the percentages being outputted as "-nan(ind)%"
- all negative inputs results in logical results if you consider the negatives as positives
- a mix of negative and positive inputs also works, if you ignore the output signs
- a mix of negatives and positives where the total = 0 breaks the code and "inf%" being outputted
- in all scenarios, the else-case runs (Democrats)

Inducing a Logical Error
- I changed the percentage calculations to be incorrectly calculated out of the individual seats rather than the total.
- This resulted in the percentages all being outputted as 100% since any number divided by itself is 1.
- This is nonsensical since all three types cannot be 100% of the total seats, but it is consistent with the logic error made.
- Since the unused variable "total" was throwing a warning in g31, I commented out that line.

Inducing a Compilation Error
- I removed all 22 semicolons from the main block.
- All 22 "syntax errors" were detected, each detailing the line where it occurs.
- The errors stated that something like "int" should be PREceded by ";" which makes sense since the previous line of code lacked a closing ";"
- Each unique error had a unique identification code, so while all of them were semicolon errors, "syntax error: missing ';' before 'if'" had a different code
than "syntax error: 'int' should be preceded by ';'"