from test_generator import random_generator

out = open("data.in", "w")
print("introduceti numarul de teste pe care vreti sa le creati:")
no_test = int(input())

out.write("%d\n" % no_test)
out.close()

random_generator(no_test)
