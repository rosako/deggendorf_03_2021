# Semi-automated Ghidra!

## part 1 - Scripting warmup + logs overview

1. Look for interesting strings, they could typically be verbose enough to give you an insight of what the function is doing.
2. Check which function are using these strings, if they are unfamiliar to you try to guess
3. There might be a significant amount of calls, write a script that
	..a. Find that function address
	..b. Get all the xref to that function
	..c. Print all the xref functions along with their arguments
4. Questions
	..a. Which function did you believe was interesting?
	..b. Could you more or less infer what each function was more or less doing, without reading any code yet?

	
## part 2 - Basic scripting - Vuln hunting helper

1. In C, as a memory unsafe language, there are some functions that are prone to vulnerable usage. Among them, (strcpy, scanf, memcpy, ...).
	..a. Keep in mind what you saw in the first part (hint: prefix)
2. Write a script that
	..a. Look for all the occurrences in the symbol tree
	..b. Gather the xref to the function
	..c. For each banned function print the function caller
	..d. Rename these functions with "inspect_" so you can come back to them later
	


## part 3 - Overview analysis

1. Look at the main function to understand what it is going on
2. What are the outgoing call functions?
	..a. You can write a script to find all the functions that are called from there
	..b. You can use the function call trees view
3. handshake function
	..a. What is this function doing (obvious)
	..b. What does the handshake look like?
	..c. Can you already guess the response format?
	..d. What is the protocol 
	..e. Can you guess the first and second argument?
	..f. Do you see a potential defined structure? (session)
4. token creation
	..a. Which function is responsible for generating token?
	..b. What's the function's arguments?
	..c. How is the authentication token generated? Does it look secure?
	..d. If not, what's wrong?
5. Look into the set_nickname function
	..a. Can you guess the argument? (easy if you did the previous point)
	..b. What is its type?
	..c. What is this function doing?
	..d. Can you find an issue?

6. Message handling
	..a. Parsing are usually interesting areas for vulnerability hunting, what can you deduce looking at the parse_message function?
	..b. What is the parameter, where does it come from?
	..c. What are the checks being done on this parameter?
	..d. What about the msg_parse_token function?
		1. What are the arguments?
		2. How is the message tokenized?

7. Message sending
	..a. What is the function responsible for sending message to the server?
	..b. At this stage, would you rather continue trying to statically analyze the code?

	
## part 4 - Network protocol analysis

1. Network traffic analysis
	..a. Open wireshark on the loopback interface
	..b. Start the server, then the client
	..c. Enter your nickname, then try to send a few messages
	..d. Which port is used for this messaging protocol?
	..e. What is the message format? Does it match our previous assumption?
	..f. Which different message types can you see?

	

## part 5 - Basic vulnerability analysis

1. Attack strategies / vectors
	..a. How would you attack this kind of network protocol? (no wrong answer here)
	..b. What are the "hot" areas we deduced from the static analysis?
2. Try to conduct basic fuzzing against the server
	..a. Could you make the target crash?
	..b. If yes, how did you proceed and which function was responsible for the crash?







	
