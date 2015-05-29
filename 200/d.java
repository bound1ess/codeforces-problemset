import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.AbstractMap.SimpleEntry;
import java.util.List;
import java.util.ArrayList;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class d {
    private static final Pattern funcRegex = Pattern.compile("(.+)\\((.+)\\)");

    public static void main(String[] cliArgs) throws IOException {
        Map<String, String> vars = new HashMap<>();
        Map<String, List<List<String>>> funcs = new HashMap<>();

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());

        for (int i = 0; i < n; i++) {
            String funcDecl = reader.readLine().trim().substring(4);
            Matcher funcMatcher = funcRegex.matcher(funcDecl.replaceAll("\\s+", ""));

            funcMatcher.find();

            if ( ! funcs.containsKey(funcMatcher.group(1))) {
                funcs.put(funcMatcher.group(1), new ArrayList<List<String>>());
            }

            List<String> args = new ArrayList<>();

            for (String arg: funcMatcher.group(2).split("\\,")) {
                args.add(arg);
            }

            funcs.get(funcMatcher.group(1)).add(args);
        }

        int m = Integer.parseInt(reader.readLine());

        for (int i = 0; i < m; i++) {
            String[] varDecl = reader.readLine().trim().split("[\\s]+");
            vars.put(varDecl[1], varDecl[0]);
        }

        int k = Integer.parseInt(reader.readLine());
        List<Entry<String, List<String>>> calls = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            Matcher callMatcher = funcRegex.matcher(reader.readLine().replaceAll("\\s+", ""));
            callMatcher.find();

            List<String> args = new ArrayList<>();

            for (String arg: callMatcher.group(2).split("\\,")) {
                args.add(vars.get(arg));
            }

            calls.add(new SimpleEntry<String, List<String>>(callMatcher.group(1), args));
        }

        reader.close();

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        for (Entry<String, List<String>> call: calls) {
            int answer = 0;

            for (Entry<String, List<List<String>>> func: funcs.entrySet()) {
                if ( ! func.getKey().equals(call.getKey())) {
                    continue;
                }

                for (List<String> args: func.getValue()) {
                    if (args.size() != call.getValue().size()) {
                        continue;
                    }

                    boolean correct = true;
                    int i = 0;

                    for (String arg: args) {
                        if (arg.equals("T")) {
                            i++;
                            continue;
                        }

                        if ( ! arg.equals(call.getValue().get(i))) {
                            correct = false;
                            break;
                        } else {
                            i++;
                        }
                    }

                    if (correct) {
                        answer++;
                    }
                }
            }

            writer.write(answer + "\n");
        }

        writer.close();
    }
}
