# start zookeeper server
bin/zookeeper-server-start.sh config/zookeeper.properties

# start kafka server
bin/kafka-server-start.sh config/server.properties

# create a topic named "test" with a single partition and only one replica
bin/kafka-topics.sh --create --zookeeper localhost:2181 --replication-factor 1 --partitions 1 --topic test

# producer some messages
bin/kafka-console-producer.sh --broker-list localhost:9092 --topic test
bin/kafka-console-producer.sh --broker-list zt92:9092,zt93:9092,zt94:9092 --topic test

# consumer some messages
bin/kafka-console-consumer.sh --zookeeper localhost:2181 --topic test
bin/kafka-console-consumer.sh --zookeeper zt92:2181,zt93:2181,zt94:2181 --topic test

# consumer a topic from beginning
bin/kafka-console-consumer.sh --zookeeper localhost:2181 --topic test --from-beginning
bin/kafka-console-consumer.sh --zookeeper zt92:2181,zt93:2181,zt94:2181 --topic test --from-beginning

# Now create a new topic with a replication factor of three
bin/kafka-topics.sh --create --zookeeper localhost:2181 --replication-factor 3 --partitions 3 --topic test

# desc topic
bin/kafka-topics.sh --describe --zookeeper localhost:2181 --topic test
bin/kafka-topics.sh --describe --zookeeper zt92:2181,zt93:2181,zt94:2181 --topic test

# Consumer Offsets
/consumers/[group_id]/offsets/[topic]/[broker_id-partition_id] --> offset_counter_value ((persistent node)

# Partition Owner registry
/consumers/[group_id]/owners/[topic]/[broker_id-partition_id] --> consumer_node_id (ephemeral node)