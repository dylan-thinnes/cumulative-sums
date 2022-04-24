x = 0
for line in eachline()
  global x += parse(BigInt, line)
end
print(x)
