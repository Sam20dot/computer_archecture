from fastapi import FastAPI
from pydantic import BaseModel



# first ove all we create the engine which can be used for creating other things 
app=FastAPI()

# the list of the users 

user_database =[]

# then we create the model for them user like what is most required for the users 

class user_allowed (BaseModel) :
    name:str


# then we write the end point of adding the user withi the file 

@app.post("/create_user") 
async def create_user (user:user_allowed):
    user_database.append (user.name)
    return {
            "user name ": user.name,
            "message"   :"you have done what is amazing and we are proud of you !!!"


            }




