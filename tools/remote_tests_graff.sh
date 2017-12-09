COMMAND='rm -rf hlibc ; git clone https://www.github.com/cmgraff/hlibc; cd hlibc ; make test'
LLVMCOMMAND='rm -rf clanghlibc ; git clone https://www.github.com/cmgraff/hlibc clanghlibc; cd clanghlibc ; make testclang'

test_i386()
{
	ssh cgraff1@gcc45.fsffrance.org -f "$COMMAND"
}
test_i386 > test_i386_log 2>&1

test_x86_64()
{
	ssh cgraff1@gcc75.fsffrance.org -f "$COMMAND"
}
test_x86_64 > test_x86_64_log 2>&1

test_arm()
{
	ssh cgraff1@arm.zv.io -f "$COMMAND"
}
test_arm > test_arm_log 2>&1

test_arm_clang()
{
	ssh cgraff1@arm.zv.io -f "$LLVMCOMMAND"
}
test_arm > test_arm__clang_log 2>&1
