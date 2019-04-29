#include<linux/init.h>
#include<linux/module.h>
#include <linux/sched.h>
#include<linux/fs.h>
#include<asm/uaccess.h>

MODULE_LICENSE("GPL");

static char device_buf[100];
int read_pos = 0;

int mydev_open(struct inode * i, struct file * f) {
	printk(KERN_ALERT "Device opened for %s", "myDev");
	return 0;
}

ssize_t mydev_read(struct file * f, char * buff, size_t len, loff_t * off) {
	int cnt = 0;
	while(len && device_buf[read_pos] != 0) {
		put_user(device_buf[read_pos], buff++);
		cnt++;
		len--;
		read_pos++;
	}
	return cnt;
}

ssize_t mydev_write(struct file *f, const char *buff, size_t len, loff_t *off) {
	short idx = len-1, cnt = 0;
	memset(device_buf, 0, 100);
	read_pos = 0;
	printk(KERN_INFO "Lenght of string is %d", len);
	while(len > 0) {
		device_buf[cnt++] = buff[idx--];
		len--;
	}
	return cnt;
}

int mydev_close(struct inode * i, struct file * f) {
	printk(KERN_ALERT "Device closed for %s", "myDev");
	return 0;
}

struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = mydev_read,
	.open = mydev_open,
	.write = mydev_write,
	.release = mydev_close,
};

int hello_init(void) {
	printk(KERN_ALERT "Init\n");
	int t = register_chrdev(90, "myDev", &fops);
	if(t < 0) printk(KERN_ALERT "Device registration failed..\n");
	else printk(KERN_ALERT "Device registered..\n");
	return t;
}

void hello_exit(void) {
	unregister_chrdev(90, "myDev");
	printk(KERN_ALERT "Exit\n");
}

module_init(hello_init);
module_exit(hello_exit);


