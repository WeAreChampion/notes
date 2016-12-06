# expand our cluster to three nodes
# link: http://kafka.apache.org/090/documentation.html#introduction
# downloads : https://www.apache.org/dyn/closer.cgi?path=/kafka/0.9.0.0/kafka_2.11-0.9.0.0.tgz
tar -xzf kafka_2.11-0.9.0.0.tgz

cd kafka_2.11-0.9.0.0

################### edit server.properties ###################
vim config/server.properties

# The broker.id property is the unique and permanent name of each node in the cluster. 
# We have to override the port and log directory only because we are running these all on the same machine
# and we want to keep the brokers from all trying to register on the same port or overwrite each others data.
# If only one host then broker.id, log.dir, port must different in different server.properties.
broker.id=0

# zookeeper connect change
# muli zookeeper hosts then split by ','
zookeeper.connect=host1:2181,host2:2181,host3:2181

################### edit consumer.properties ###################
vim config/consumer.properties

# zookeeper connect change
# muli zookeeper hosts then split by ','
zookeeper.connect=zt92:2181,zt93:2181,zt94:2181

# copy the kafka settings to other host and change the broker.id value in server.properties
scp -r kafka_home host:/dir

################### edit producer.properties ###################
vim config/producer.properties

# the producer cluster
# muli hosts then split by ','
metadata.broker.list=zt92:9092,zt93:9092,zt94:9092

# start in every host
bin/kafka-server-start.sh config/server.properties &