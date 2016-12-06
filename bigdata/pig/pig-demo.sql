--max_temp.pig : Finds the max temperature by year
-- default spliter is '\t'
records = LOAD 'hdfsFileOrDir' >> AS (year:chararray, temperature:int, quality:int);

-- output the records
--DUMP records;
-- describe the table
-- describe records;

-- filter the records
-- false will filter the records.
filtered_records = FILTER records BY temperature != 9999 AND (quality == 0 OR quality == 1 OR quality == 4 OR quality == 5 OR quality == 9);

-- group recordsName by field
-- same key records add in list
grouped_records = GROUP filtered_records BY year;

-- foreach the table and get the group(year)
max_temp = FOREACH grouped_records GENERATE group, MAX(filtered_records.temperature)