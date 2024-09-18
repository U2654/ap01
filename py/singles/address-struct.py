class Address:
    name = ""       # the default values indicate the type
    street = ""
    postcode = 0
    city = ""

address = Address()         #  struct has the default values initially
address.name = "S. Error"
address.street = "Bus 0"
address.postcode = 6502
address.city = "Processor"

print(address.name)