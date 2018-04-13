import os

# SYSTEM SOURCES
i = 1
print "\nStarting Test Cases\n---"
while (i <= 23):
    print "Running Test Case "+str(i)
    os.system("\Release\AutoTester \AutoTester\Test-Cases\sources\testcase"+str(i)+"-source.txt \AutoTester\Test-Cases\queries\testcase"+str(i)+"-queries.txt \AutoTester\Test-Cases\output\testcase"+str(i)+"-out.xml")
    i = i + 1

i = 1
print "---\nCompleted Test Cases"
print "\nStarting Blackbox\n---"
while (i <= 2):
    print "Running Blackbox "+str(i)
    os.system("\Release\AutoTester \AutoTester\Test-Cases\sources\\blackbox"+str(i)+"-source.txt \AutoTester\Test-Cases\queries\\blackbox"+str(i)+"-queries.txt \AutoTester\Test-Cases\output\blackbox"+str(i)+"-out.xml")
    i = i + 1

i = 1
print "---\nCompleted Blackbox"
print "\nStarting Extension\n---"
while (i <= 2):
    print "Running Extension "+str(i)
    os.system("\Release\AutoTester \AutoTester\Test-Cases\sources\extension"+str(i)+"-source.txt \AutoTester\Test-Cases\queries\extension"+str(i)+"-queries.txt \AutoTester\Test-Cases\output\extension"+str(i)+"-out.xml")
    i = i + 1
print "---\nCompleted Extension"