"""
    Send mail from gmail account
    Instructions for configuration:
    1. go to https://myaccount.google.com/lesssecureapps
    2. turn on "Allow less secure apps"
"""
import smtplib

def send_email (to, gmail_user, gmail_password, msg):
    """
    Function which sends mail from gmail account
    Parameters (send_to, gmail_user, gmail_password, msg):
    types:
    send_to           string
    gmail_user        string
    gmail_password    string
    msg               string

    returns nothing

    credit to:
    https://mkyong.com/python/how-do-send-email-in-python-via-smtplib/

    """
    try:
        smtpserver = smtplib.SMTP("smtp.gmail.com",587)
        smtpserver.ehlo()
        smtpserver.starttls()
        smtpserver.login(gmail_user, gmail_password)
        smtpserver.sendmail(gmail_user, to, msg)
        smtpserver.close()
    except Exception as e:
        print(e)
