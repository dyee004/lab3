# Test file for Lab4_stateMachine


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "PINA: 0x3F => PORTB: 0x03, PORTC: 0xF0"
setPINA 0x3F
continue 6
expectPORTB 0x03
expectPORTC 0xF0
checkResult

test "PINA: 0x25=> PORTB: 0x02, PORTC: 0x50"
setPINA 0x25
continue 6
expectPORTB 0x02
expectPORTC 0x50
checkResult

test "PINA: 0xE5 => PORTB: 0x0E, PORTC: 0x50"
setPINA 0xE5
continue 6
expectPORTB 0x0E
expectPORTC 0x50
checkResult

test "PINA: 0x39 => PORTB: 0x03, PORTC: 0x90"
setPINA 0x39
continue 6
expectPORTB 0x03
expectPORTC 0x90
checkResult

test "PINA: 0x71 => PORTB: 0x07, PORTC: 0x10"
setPINA 0x71
continue 6
expectPORTB 0x07
expectPORTC 0x10
checkResult

test "PINA: 0x00 => PORTB: 0x00, PORTC: 0x00"
setPINA 0x00
continue 6
expectPORTB 0x00
expectPORTC 0x00
checkResult

# Add tests below

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
