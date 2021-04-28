# What the H?

### Adding the binary to the project

A project should contain target binaries that are somehow related to the same analysis project (DOW!!). If you were to work on these in real life, you would likely create a separate project for each of them. Since our main goal/project here is to get familiar with `Ghidra`, we will keep them all into one project (I mean, feel free to do it otherwise.

1. Go to `Ghidra`'s project manager, and type `i` to import a new file
2. Select `deggendorf_03_2021/ghidra/01_sharing_caring/libcaring.a`
3. You will get a message prompt,
	1. What is it about?
	2. What does it mean?

4. Try to import it with each of these options, and figure out why these different choices.


### Our analysis

As we discussed during the presentation, our analysis approach mainly depends on our goal. Also, reverse engineering does not necessarily (well most of the time) mean fully understanding our target. Instead, we keep our focus on our end goal.

In this case, your goal is to understand what this library does, without actually digging into the code that much.

1. Unroll the `Functions` folder inside the `Symbol Tree`
2. Look at the function names
	1. Do they sound familiar?
	2. Try to look them up on your favorite search engine
3. Select each of the function (there are not many)
	1. Skim through the code in the `decompile` view
	2. Whenever you see some constant or pattern that look interesting, look them up
4. Just by doing so, you should come up with some ideas.
	1. Hint : special attention to `CARINGInit`

At this point, we know it is a well known library, simply compiled with renamed symbols. 


### Bonus

Write a Ghidra script to automatically recognize this library. Take your time, start as simple as possible.

1. Figure out which patterns, constants, or any other aspect are specific to this library
2. Write a script that goes through all the symbols and check whether they contain these specific aspects.
	1. If they do, mark them with a prefix.





