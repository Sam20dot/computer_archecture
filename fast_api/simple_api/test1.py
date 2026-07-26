from fastapi import FastAPI 


app=FastAPI ()


# then we are going to write the api for getting somethings 
@app.get ("/") 

async def getName () :
    return {"message":"we are getting this real"}

@app.get ("/sam")
async def getPoeple () :
    return {"name":"NIZAWE AIME SAM PRAY"}


# when we are doing the things they obsessed 
@app.get ("/hello") 
async def getDevice () :
    return {"device_name":"esp_32", "id":321}


# then we are going to use the post man to test this things 
@app.post ("/name") 
async def create_device (user_name):
    return {"name is ":user_name}
    
