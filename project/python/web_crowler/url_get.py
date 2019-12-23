import re
url_list=[]
def main():
    with open('url.txt','r') as f:
        s=f.read()
        url_list=re.findall('(/lms#/video/13751/34545.*?)\"',s,re.S)
    with open('url_course.txt',"w") as fw :
        for i in url_list :
            fw.write('https://cquv3.xuetangx.com'+i+'\n')
main()
