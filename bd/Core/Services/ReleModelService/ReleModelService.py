from typing import List
from ..BaseService import BaseService
from bd.Models.Models import ReleModel

class ReleModelService(BaseService):
    def __init__(self) -> None:
        super().__init__(ReleModel)