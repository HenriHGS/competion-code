防火墙的入门，start
```bash
firewall -cmd --state
-bash: firewall: command not found
[root@localhost ~]# firewall-cmd --state
running
[root@localhost ~]# firewall-cmd --list-port

[root@localhost ~]# firewall-cmd --zone=public --add-port=1234/tcp --permanent
success
[root@localhost ~]# firewall-cmd --list-port

[root@localhost ~]# firewall-cmd --reload
success
[root@localhost ~]# firewall-cmd --list-port
```

常见工具的下载
```bash
yum -y install net-tools
```

系统命令
```bash
ulimit -a # 查看到一些限制
ulimit -HSn 2000 # 把文件数修改为2000
```