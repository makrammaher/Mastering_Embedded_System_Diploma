ENTRY(Reset_handler)

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text)
	}> flash

	.rodata :
	{
		*(.rodata)
		_E_TEXT = . ;
	}> flash
	.data :
	{
		_S_DATA = . ;
		*(.data)
		. = ALIGN(4);
		_E_DATA = . ;
	}> sram AT> flash

	.bss :
	{
		_S_BSS = .;
		*(.bss)
		. = ALIGN(4);
		_E_BSS = .;
	}> sram
	. = . + 0x1000;
	_STACK_TOP = .;
}