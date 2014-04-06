web_brute
=========

Programm for webbrute without password lists.

It isn't finished yet!!!

It should send http-requests and identify succesfull Login-Data
via differences in returned website source code.

Example: ./vbrute -t 2 -m 3 -l 5 -u vaphen.funpic.de -a c

t = Threadcount
m = Min. length of password
l = Max. length of password
u = Url
a = astriction (c = chars only)
