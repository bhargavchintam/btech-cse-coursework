// average salary per department
// input line: dept,salary

import java.io.IOException;

import org.apache.hadoop.conf.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class AverageSalary {

    public static class SalaryMapper
            extends Mapper<LongWritable, Text, Text, IntWritable> {

        public void map(LongWritable key, Text value, Context context)
                throws IOException, InterruptedException {
            String[] parts = value.toString().split(",");
            if (parts.length == 2) {
                String dept = parts[0].trim();
                int sal = Integer.parseInt(parts[1].trim());
                context.write(new Text(dept), new IntWritable(sal));
            }
        }
    }

    public static class AverageReducer
            extends Reducer<Text, IntWritable, Text, DoubleWritable> {

        public void reduce(Text key, Iterable<IntWritable> values, Context context)
                throws IOException, InterruptedException {
            int sum = 0;
            int count = 0;
            for (IntWritable val : values) {
                sum += val.get();
                count++;
            }
            double avg = (double) sum / count;
            context.write(key, new DoubleWritable(avg));
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "average salary");
        job.setJarByClass(AverageSalary.class);
        job.setMapperClass(SalaryMapper.class);
        job.setReducerClass(AverageReducer.class);
        job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(IntWritable.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(DoubleWritable.class);
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
