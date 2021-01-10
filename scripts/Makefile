TESTDIR=../tests
SRCDIR=../src

default:
	@g++ -Wall -I${SRCDIR} ${TESTDIR}/test_genesis.cpp -o genesis.x; ./genesis.x

tmsg:
	@g++ -I${SRCDIR} ${TESTDIR}/test_msg.c -o msg.x; ./msg.x

clean:
	@rm -rf *.out *.log *.x
