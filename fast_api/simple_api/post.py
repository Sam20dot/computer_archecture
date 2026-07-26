# now we are going to create the post query to do it 
from fastapi      import FastAPI 
from pydantic     import BaseModel 

app=FastAPI()


# here we have to create the different characteristics which can be good to discribe this all so that i can do it very well 

class userPayload (BaseModel) :
    user_name:str


class devicePayload (BaseModel):
    device_id:    str
    device_name:  str


class cars(BaseModel) :
    car_name:str
    car_cost:int


# post testing to see what i am getting for this now 

@app.post ("/create") 
async def create_user (payload:userPayload) :
    return {"the name is ":payload.user_name}


@app.post ("/create_device") 
async def create_def (device:devicePayload) :
    return {
            "the device id is   ":device.device_id,
            "the device name is ":device.device_name
            }

@app.post ("/create_car")

async def create_car (car:cars) :
    return {"the car name is ":car.car_name, "car cost is ":car.car_cost}





