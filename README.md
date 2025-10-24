### Chester's Cheetos Client
	To-Do: 
		Latch onto other processes (not just javaw.exe)
		Auto Clicker
		Aim Assist
		Reach
		Sprint
		Self-destruct process
	Features:
		Latches onto javaw.exe
		-> Inject native DLL into Minecraft process (javaw.exe) using SI or CE
		Java virtual machine attaches injection thread to game using JNI
		Lightweight object wrapper
		Debug console
		Hotkey to self-destruct
