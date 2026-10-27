// letter count - count each alphabet letter in the input

import java.io.IOException;

import org.apache.hadoop.conf.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class LetterCount {

    public static class LetterMapper
            extends Mapper<Object, Text, Text, IntWritable> {

        private final static IntWritable one = new IntWritable(1);
        private Text letter = new Text();

        public void map(Object key, Text value, Context context)
                throws IOException, InterruptedException {
            String line = value.toString().toLowerCase();
            for (int i = 0; i < line.length(); i++) {
                char c = line.charAt(i);
                if (c >= 'a' && c <= 'z') {
                    letter.set(String.valueOf(c));
                    context.write(letter, one);
                }
            }
        }
    }

    public static class LetterReducer
            extends Reducer<Text, IntWritable, Text, IntWritable> {

        private IntWritable result = new IntWritable();

        public void reduce(Text key, Iterable<IntWritable> values, Context context)
                throws IOException, InterruptedException {
            int sum = 0;
            for (IntWritable val : values) {
                sum += val.get();
            }
            result.set(sum);
            context.write(key, result);
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "letter count");
        job.setJarByClass(LetterCount.class);
        job.setMapperClass(LetterMapper.class);
        job.setCombinerClass(LetterReducer.class);
        job.setReducerClass(LetterReducer.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
