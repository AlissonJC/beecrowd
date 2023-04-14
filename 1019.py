# Read an integer value, which is the duration in seconds of a certain event
# in a factory, and inform it expressed in hours:minutes:seconds.
#
# Input
# The input file contains an integer N.
#
# Output
# Print the read time in the input file (seconds) converted in hours:minutes:seconds
# like the following example.

duration = int(input())

hours = duration // 3600
duration -= hours * 3600
minutes = duration // 60
duration -= minutes * 60
seconds = duration

print(f"{hours:.0f}:{minutes:.0f}:{seconds:.0f}")
