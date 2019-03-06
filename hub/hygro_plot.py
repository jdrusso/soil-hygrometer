#!/usr/bin/env python3
# Hygrometer logfile should be passed to this as a command line option
# Logfiles are expected to be in the format
# [DATE]\n
# [HYGROMETER VALUE]\n
# \n
# ...repeat...

import fileinput
import matplotlib as mpl
from matplotlib import pyplot as plt
from datetime import datetime, timezone
import dateutil

def utc_to_local(utc_dt):
    return utc_dt.replace(tzinfo=timezone.utc).astimezone(tz=None)

logfile = fileinput.input()

data = [x[:-1] for x in logfile if not x == '\n']

# Parse date/times
dates = [datetime.strptime(x, '%a %b %d %H:%M:%S %Z %Y') for x in data[::2]]
dates = [utc_to_local(x) for x in dates] # Convert to local timezone
dates = mpl.dates.date2num(dates) # Convert to matplotlib format

# Get hygrometer readings from data
values = [int(x) for x in data[1::2]]

mpl.rcParams['timezone'] = 'EST'
plt.plot_date(dates, values, markersize=.1, linestyle='solid')
plt.ylabel("Soil dryness")
plt.xlabel("Date & Time")

plt.show()
