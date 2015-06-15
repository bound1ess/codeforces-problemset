n = gets.to_i
a = gets.split.map(&:to_i)[1..-1]
b = gets.split.map(&:to_i)[1..-1]

puts a.concat(b).uniq.size == n ? 'I become the guy.' : 'Oh, my keyboard!'
