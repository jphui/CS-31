# Project 7 - Multi-Class PIG Game

**Difficulties Encountered**

a. Total for Computer not showing up
- This was an early issue I had where the score for computer wouldn’t display, but I realized that I had mixed up computerTotal and computerScore.

b. Where to “delegate” score handling
- This was a very broad issue I was having where the way the spec was worded made it seem all scoring should be handled in the Board and Pig classes, thus rendering the Player class useless for scorekeeping. However, I soon realized that scoring should be handled by Player, with Pig acting as a “manager”, calling functions as needed to handle, well, game logic

c. GameOver not working correctly
- This was my biggest issue overall, where my code was not able to tell whether the game was ending at the Pig level. What I was doing was that I was simultaneously trying to handle scoring at the Pig and Player levels (see b), so the effect was that once I correctly changed scores and totals in the Player level, I would override then in the Pig level unknowingly. Easy fix.

d. Ending the game like it is on the website
- I was attempting to end the game like it plays out on the website, where score + total > 30 would be enough to say, hey, I win. However, this failed the asserts and I realized that our approach was more simplified.

**Test Cases**

There is a LOT of code that can be written to test individual aspects of this comparatively huge project, so I will highlight 4 “cases” that are important to ensure functionality.

a. Winning at total = 30
- I ran into this issue when the computer score displayed as 30 but the game continued to allow me to roll. Making sure that your code designates a winner and thus, a game over is important at the total=30 level.

b. Purposefully trying to edit game data after the game is over
- This is part of the test code that Stahl gave us but being able to resist changes after the game is done ensures your code for updating player scores is correct.

c. h.getTotal() == board.mHuman.getTotal()
- These isn’t the exact code to write but making sure that the total “stored privately in Player” is equal to the values that the Board is keeping track of match and ensure that you are correctly updating the scores through the getter and setters.

d. Making sure you don’t get a premature win
- This is directly related to D from the previous question. If we were modeling the game as it is run on the website, there would be the issue where you could declare a winner before the total is updated to >= 30 because the rolled value is enough to add up to >= 30. Asserting values that make sure the game doesn’t end until the total itself is actually >= 30 is important.
