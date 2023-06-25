from ..Repository.BaseRepository import BaseRepository


class BaseService(BaseRepository):
    def __init__(self, entity) -> None:
        super().__init__(entity)