# Semi-automated Ghidra!

## part 1 - Scripting warmup + logs overview

1. Look for interesting strings, they could typically be verbose enough to give you an insight of what the function is doing.
2. Check which function are using these strings, if they are unfamiliar to you try to guess
3. There might be a significant amount of calls, write a script that
	1. Find that function address
	2. Get all the xref to that function
	3. Print all the xref functions along with their arguments
4. Questions
	1. Which function did you believe was interesting?
	2. Could you more or less infer what each function was more or less doing, without reading any code yet?

	
## part 2 - Basic scripting - Vuln hunting helper

1. In C, as a memory unsafe language, there are some functions that are prone to vulnerable usage. Among them, (`strcpy`, `scanf`, `memcpy`, ...).
	1. Keep in mind what you saw in the first part (hint: prefix)
2. Write a script that
	2. Look for all the occurrences in the symbol tree
	3. Gather the xref to the function
	4. For each banned function print the function caller
	5. Rename these functions with `inspect_` so you can come back to them later
	


## part 3 - Overview analysis

1. Look into the `main` function to understand what it is going on
2. What are the outgoing call functions?
	1. You can write a script to find all the functions that are called from there
	2. You can use the function call trees view
3. Look into the `handshake` function
	1. What is this function doing (obvious)
	2. What does the handshake look like?
	3. Can you already guess the response format?
	4. What is the protocol 
	5. Can you guess the first and second argument?
	6. Do you see a potential defined structure? (session)
4. token creation
	1. Which function is responsible for generating token?
	2. What's the function's arguments?
	3. How is the authentication token generated? Does it look secure?
	4. If not, what's wrong?
5. Look into the `set_nickname` function
	1. Can you guess the argument? (easy if you did the previous point)
	2. What is its type?
	3. What is this function doing?
	4. Can you find an issue?

6. Message handling
	1. Parsing are usually interesting areas for vulnerability hunting, what can you deduce looking at the `parse_message` function?
	2. What is the parameter, where does it come from?
	3. What are the checks being done on this parameter?
	4. What about the `msg_parse_token` function?
		- What are the arguments?
		- How is the message tokenized?

7. Message sending
	1. What is the function responsible for sending message to the server?
	2. At this stage, would you rather continue trying to statically analyze the code?

	
## part 4 - Network protocol analysis

1. Network traffic analysis
	1. Open wireshark on the loopback interface
	2. Start the server, then the client
	3. Enter your nickname, then try to send a few messages
	4. Which port is used for this messaging protocol?
	5. What is the message format? Does it match our previous assumption?
	6. Which different message types can you see?

	

## part 5 - Basic vulnerability analysis

1. Attack strategies / vectors
	1. How would you attack this kind of network protocol? (no wrong answer here)
	2. What are the "hot" areas we deduced from the static analysis?
2. Try to conduct basic fuzzing against the server
	1. Could you make the target crash?
	2. If yes, how did you proceed and which function was responsible for the crash?
