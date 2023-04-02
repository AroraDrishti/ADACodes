import pymongo
import pandas as pd

client = pymongo.MongoClient("mongodb://localhost:27017/")
client = print(client)

db = client['Assignment']
print(db)

collection = db['Ads_dataset']
print(collection)

rec = collection.find_one()
print(rec)