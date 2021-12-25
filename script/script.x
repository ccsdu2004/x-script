let a = 3
let b = 3.2f
let c = "hello world"
let d = [True,","]
let e = 3.14159625
let flag = False
let long = L12345678
let dict = {'name':'XScript','version':'0.01'}

## this is x script!

function sum(a,b)
    return a + b
end

let total = sum(3,4)
print total

if a > b
    print a,'>',b
elseif
    print a,'=',b
else
    print a,'<',b
end

for i in [1->10:1]
    print i
end

let index = 0
while(True)
    index = index + 1
    if index > 10:
        break
    print index
end
