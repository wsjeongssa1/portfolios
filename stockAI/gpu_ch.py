import tensorflow as tf

hello = tf.constant('Hello, TenserFlow!')
sess = tf.Session()
print(sess.run(hello))
