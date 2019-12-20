import requests
from io import BytesIO
from PIL import Image
import re
s=requests.Session()
def show_image():
    capt_url='ttps://cquv3.xuetangx.com/api/v1/code/captcha'
    capt=s.get(capt_url).content
    with BytesIO() as f:
        f.write(capt)
        im=Imgae.open(f) 
        im.show()
    return input('input captcha')
def main():
    url='https://cquv3.xuetangx.com/#/home'
    headers={
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36'
    }
    s.get(url)
    s.headers=headers
    captcha=show_image()
    data={
        'login':'15984889957',
        'password':'9704790k',
        'captcha':captcha,
        'is_alliance':0
    }
    login_url='https://cquv3.xuetangx.com/api/v1/oauth/number/login'
    res=s.post(login_url,data=data,allow_redirects=True)
    print(res.content)
main()