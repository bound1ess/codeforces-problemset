require "fileutils"

files = Dir["*.java"] + Dir["*.cpp"]
#puts files.inspect
for orig_path in files
    path = orig_path.clone

    if path.end_with?(".java")
        path.chomp!(".java")
    else
        path.chomp!(".cpp")
    end

    path = path[0...-1] # cut task ID (a, b, c, d etc)

    if path.start_with?("_")
        path = path[1..-1]
    end

    #puts path
    path = File.join(Dir.getwd, path)

    Dir.mkdir(path) if not Dir.exists?(path)

    src = File.join(Dir.getwd, orig_path)
    dest = File.join(path, orig_path.gsub(/[_0-9]+/, ''))

    #puts "#{src} ===> #{dest}"
    FileUtils.copy(src, dest)
end
