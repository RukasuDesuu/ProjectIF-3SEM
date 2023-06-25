from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

class DbConnection():
    _instance = None

    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            cls._instance = super().__new__(cls)
        return cls._instance

    def __init__(self) -> None:
        if not hasattr(self, 'engine'):
            self.engine = create_engine('sqlite:///ademar.sqlite')
            self.Session = sessionmaker(bind=self.engine)
    
    def get_session(self) -> sessionmaker:
        return self.Session()