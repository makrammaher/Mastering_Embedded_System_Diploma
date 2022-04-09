#Make reset symbole global
.global reset

#reset Section in startup.s
reset:
	ldr	sp, =stack_top
	bl 	main

#stop Section Infinite loop
stop:
	b 		stop
