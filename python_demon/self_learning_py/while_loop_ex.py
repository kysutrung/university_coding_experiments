var_a = 7 #muốn in bao nhiêu số đầu của dãy fibonaci
var_b = 0
num_a, num_b = 0, 1
count = 0

while count < var_a:
    print(num_a, end=' ')
    var_b = num_b
    num_b = num_a + num_b
    num_a = var_b
    count += 1


    