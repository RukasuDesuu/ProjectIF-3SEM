from typing import TypeVar, Generic, List
from ..DbConnection import DbConnection
from sqlalchemy.orm import Session

T = TypeVar('T')

class BaseRepository(Generic[T]):
    _db: DbConnection
    _session: Session
    _entity: T

    def __init__(self, entity: T) -> None:
        self._db = DbConnection()
        self._session = self._db.get_session()
        self._entity = entity

    def get_all(self) -> List[T]:
        return self._session.query(self._entity).all()

    def get_by_id(self, id:int) -> T:
        return self._session.query(self._entity).get(id)

    def add(self, entity: T) -> None:
        self._session.add(entity)
        self._session.commit()

    def update(self, entity: T) -> None:
        self._session.commit()

    def delete(self, entity: T) -> None:
        self._session.delete(entity)
        self._session.commit()

    def refresh(self, entity: T) -> None:
        self._session.refresh(entity)

    def detach(self, entity: T) -> None:
        self._session.expunge(entity)