# Warming up


## Getting started with Ghidra

### Creating a project
First thing first, let's create a Ghidra project under which our files will be grouped for our analysis

1. Open the terminal and start Ghidra using `ghidra`
2. Create a new project under `File/New Project..` or simply `ctrl+N`
3. Leave the default selection (Non-Shared Project)
	1. For more information on Ghidra server and shared projects, refer to the excellent article [https://byte.how/posts/collaborative-reverse-engineering/]
4. Choose a project name and a location to store it

### Importing files
Now that your project is created, let's import our first target

1. Select the newly created folder on the list and go under `File/import file` or simply `i` to import your first file
2. Import our first binary `crackme`
3. Our target is an ELF executable and should be automatically recognized, you can just leave it as it is
4. That's all folks!

### Analyzing
1. In order to start analyzing our binary, just double-click on `crackme`
2. Select yes to prompt to proceed to the analyses
3. There are several analyses available as discussed, and thankfully most of them are cearly explained, skim through the descriptions, but you can leave everything on default for now and press `analyze`
4. Given the small size of our binary, the analyses will take a second to complete. Please note that it might take much longer on "real life" binaries


### Your actual task
1. Get on the terminal and run the target `./crackme` without argument
	1. What is the binary expecting (Duuuuh!)?
2. Run the binary a second time using whatever argument
	1. What's wrong? (Duuuuh!)?
	2. Keep note of the message
3. Go back to Ghidra and try to understand what leads to that message
	1. Open the strings window under `Window/Defined string`
	2. Type 'incorrect' on the filter field
	3. Click on the line where the message appears, so your `listing window` shows the string in its location
	4. Right-click it on the `listing window` and go under `References/Show references to..`
	5. Click the one and only line on the new floating window so your listing view jumps into the code location of our interest (00100788)
	6. Reopen the `decompiler view`, which is the first tab next to the `Defined strings` one
4. Look at the code and figure out what's going on
	1. Have look at the string comparison :)
5. Try executing the crackme with the correct password
	1. hint : "escaping is caring" :)
	




