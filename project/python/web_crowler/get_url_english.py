import re
url_list=[]
def main():
    with open('url_english.txt','r',encoding='utf-8') as f:
        s=f.read()
        url_list=re.findall('(/lms#/video/16644/36329.*?)\"',s,re.S)
    with open('url_english_course.txt',"w") as fw :
        for i in url_list :
            print(i)
            fw.write('https://cquv3.xuetangx.com'+i+'\n')
main()
