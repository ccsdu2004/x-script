let a = 3
let b = 3.2
let ms = .423423
let c = "hello world"
let d = [True,","]
let flag = False
let long = 12345678
let dict = {"name":"XScript","version":"0.01"}
let hello = "hello \"world"

## this is x script!

'''
this is comment 
not parse me

'''

function sum(a,b)
    return a + b
end

let total = sum(3,4)
print total

if a > b
    print a,">",b
elseif
    print a,"=",b
else
    print a,"<",b
end

for i in [1->10:1]
    print i
end

let index = 0
while True
    index = index + 1
    if index > 10:
        break
    end
    print index
end

let key = 3
