s = gets.strip
a = []

gets.to_i.times {
  n = gets.strip
  a.push n if n.start_with? s
}

puts a.empty? ? s : a.sort.first
