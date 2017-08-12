#!/usr/bin/python3

import subprocess

print(subprocess.check_output(['sudo','/home/pi/rfcomm/query_hygro'], shell=True))
# p = subprocess.Popen(['sudo /home/pi/rfcomm/query_hygro'],
#                      stdout=subprocess.PIPE, shell=True)
# p.wait()
# out = p.stdout.readlines()
#
# print("Got %s" % out)
