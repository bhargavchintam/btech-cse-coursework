# pull phone numbers out of some text
import re

text = """call me at 9845012345 or 98450-12345.
office is 080-23456789. old number was 044 22334455.
my friend uses +91 9000000001 sometimes."""

# 10 digit mobile numbers
mobiles = re.findall(r'\b\d{10}\b', text)
print("mobiles:", mobiles)

# numbers with a dash or space separator
parts = re.findall(r'\d{3,5}[- ]\d{6,8}', text)
print("with separator:", parts)

# with optional +91 country code
full = re.findall(r'\+?91[ ]?\d{10}', text)
print("with code:", full)

# just count how many digit groups there are
groups = re.findall(r'\d+', text)
print("digit groups found:", len(groups))
